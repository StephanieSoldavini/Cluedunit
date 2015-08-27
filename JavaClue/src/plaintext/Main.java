package plaintext;

import engine.*;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static Random rand = new Random();
    public static ArrayList<Card> solution = new ArrayList<>();
    public static ArrayList<Card> cards = new ArrayList<>();

    public static void makeSolutionAndDeal(){
        ArrayList<Char> tempChars = new ArrayList<>(Char.characters);
        ArrayList<Weapon> tempWeaps = new ArrayList<>(Weapon.weapons);
        ArrayList<Room> tempRooms = new ArrayList<>(Room.rooms);

        solution.add(tempChars.remove(rand.nextInt((tempChars.size()))));
        solution.add(tempWeaps.remove(rand.nextInt((tempWeaps.size()))));
        solution.add(tempRooms.remove(rand.nextInt((tempRooms.size()))));
        cards.addAll(tempChars);
        cards.addAll(tempRooms);
        cards.addAll(tempWeaps);


        while (!cards.isEmpty()){
            for (Player p : Player.players){
                if (!cards.isEmpty()){
                    p.addCard(cards.remove(rand.nextInt((cards.size()))));
                }
            }

        }
//        System.out.println(engine.Char.characters);
//        System.out.println(tempChars);
//        System.out.println(engine.Weapon.weapons);
//        System.out.println(tempWeaps);
//        System.out.println(engine.Room.rooms);
//        System.out.println(tempRooms);
//        System.out.println(solution);
    }

    public static void createPlayers(int numChar, int numComp) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Char> tempChars = new ArrayList<>(Char.characters);
        for (int p = 0; p<(numChar-numComp); p++){
            System.out.print(String.format("What is player %d's name? ", p));
            String name = scan.nextLine();
            System.out.println("Remaining characters:" + tempChars);
            System.out.print("What character will you be? ");
            String charName = scan.nextLine().toUpperCase();
            int cIndex = 0;
            for (Char c : tempChars){
                if (c.getAbbr().equals(charName)){
                    cIndex = tempChars.indexOf(c);
                }
            }
            new Player(name, tempChars.remove(cIndex), true, 0, null, new ArrayList<>()); //TODO deal with order, loc
        }
        for (int p = 0; p < numComp; p ++){
            new Player("Comp" + p, tempChars.remove(rand.nextInt((tempChars.size()))), false, 0, null, new ArrayList<>()); //TODO deal with, order, loc
        }
    }

//    public static String writePlayerAtLoc(Loc loc, Player player){
//        ConsoleCode.goTo(loc.y, loc.x, false) + ConsoleCode.changeTextColor("blue") + "PE"
//    }

//    public static String getColorFromChar(Char chr){
//        switch (chr.getAbbr()){
//            case "PE":
//                return "blue";
//            case "PL":
//                return "purple";
//            case "GR":
//                return "green";
//            case "WH":
//                return "white";
//            case "MU":
//                return "yellow";
//            case "SC":
//                return "red";
//            default:
//                return "white";
//        }
//    }

    public static String writeCharAtRowCol(int row, int col, Char chr){
        return ConsoleCode.goTo(row, col, false) + ConsoleCode.changeTextColor(chr.getColor()) + chr.getAbbr();
    }

    public static String blankTwoSpaces(int row, int col){
        return ConsoleCode.goTo(row, col, false) + "  ";
    }


    public static void main(String[] args) {
        System.out.println("\33[0m");
        Card.createAllCards();
        new Board(24, 25, Room.rooms);
        System.out.println("Characters: " + Char.characters);
        System.out.println("Weapons:    " + Weapon.weapons);
        System.out.println("Rooms:      " + Room.rooms);
        int numChars = 2;
        int numComp = 1;
        createPlayers(numChars, numComp);
        makeSolutionAndDeal();
        System.out.println("Solution:   " + solution);
        System.out.println("Players:    " + Player.players);
        Scanner scan = new Scanner(System.in);
        scan.nextLine();
        System.out.print("\33[1;1H\33[J");

        for (String line : FileReader.parseFileAsListofLines("data/asciiboard.txt")) {
            System.out.println(line);
        }

        scan.nextLine();
        System.out.print(ConsoleCode.goTo(1, 1, true) + "\33[J");
        for (String line : FileReader.parseFileAsListofLines("data/asciiboard.txt")) {
            System.out.println(line);
        }

        //put all characters visually on board
        for (Char chr: Char.characters){
            System.out.println(writeCharAtRowCol(chr.getHome().getY(), chr.getHome().getX(), chr));
        }

        scan.nextLine();

        System.out.println(blankTwoSpaces(0, 6) + writeCharAtRowCol(1, 6, Char.getCharByAbbr("PE")));
        scan.nextLine();


//        System.out.println("\33[25A\33[2K\33[1B\33[2K" + "This is so cool" + "\33[1B\33[2K");
//
//        scan.nextLine();
//        System.out.print("\33[1 1H\33[J");
//        for (String line : FileReader.parseFileAsListofLines("data/asciiboard.txt")) {
//            System.out.println(line);
//        }

        //System.out.println("\33[2 30H\33[42m" + "        " );

    }
}


