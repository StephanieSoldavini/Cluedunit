package plaintext;

import engine.*;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static Random rand = new Random();

    /*
    List of three card objects that is winning solution
     */
    public static ArrayList<Card> solution = new ArrayList<>();

    /*
    List of all cards
     */
    public static ArrayList<Card> cards = new ArrayList<>();

    /**
     * Make the winning solution and distribute the cards to the players
     */
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

    /**
     * Create the players using text prompts
     *
     * @param numChar: the total number of players in the game
     * @param numComp: the number of characters that are computers
     */
    public static void createPlayers(int numChar, int numComp) {
        //Create the human players
        Scanner scan = new Scanner(System.in);
        //List of all characters to choose from
        ArrayList<Char> tempChars = new ArrayList<>(Char.characters);
        //For every human
        for (int p = 0; p<(numChar-numComp); p++){
            //Get the name
            System.out.print(String.format("What is player %d's name? ", p));
            String name = scan.nextLine();
            //Get the preferred character
            System.out.println("Remaining characters:" + tempChars);
            System.out.print("What character will you be? ");
            String charName = scan.nextLine().toUpperCase();
            //Find that character object
            int cIndex = 0;
            for (Char c : tempChars){
                if (c.getAbbr().equals(charName)){
                    cIndex = tempChars.indexOf(c);
                }
            }
            //Create the player
            new Player(name, tempChars.remove(cIndex), true, 0, null, new ArrayList<>()); //TODO deal with order, loc
        }
        //Create the computer players
        for (int p = 0; p < numComp; p ++){
            new Player("Comp" + p, tempChars.remove(rand.nextInt((tempChars.size()))), false, 0, null, new ArrayList<>()); //TODO deal with, order, loc
        }
    }

    /**
     * Print a character at a location (row, col) with Conservatory as the origin
     *
     * @param row number of squares horizontally from origin
     * @param col number of squares vertically from origin
     * @param chr the character to place
     * @return a string to print to console
     */
    public static String writeCharAtRowCol(int row, int col, Char chr){
        return ConsoleCode.goTo(row, col, false) + ConsoleCode.changeTextColor(chr.getColor()) + chr.getAbbr();
    }

    /**
     * Overwrite two spaces at (row, col) with Conservatory as the origin.
     * Used for clearing the previous space of a player.
     *
     * @param row number of squares horizontally from origin
     * @param col number of squares vertically from origin
     * @return a string to print to console
     */
    public static String blankTwoSpaces(int row, int col){
        return ConsoleCode.goTo(row, col, false) + "  ";
    }

    public static void printBoard(){
        for (String line : FileReader.parseFileAsListofLines("data/asciiboard.txt")) {
            System.out.println(line);
        }
    }

    /**
     * Main for running Clue as a plaintext terminal program
     *
     * @param args
     */
    public static void main(String[] args) {
        //Reset console colors
        System.out.println("\33[0m");
        //Create all the card objects
        Card.createAllCards();
        //Create the board
        Board myBoard = new Board(24, 25, Room.rooms); //TODO XY Row Col
        //Print the cards for test purposes TODO remove
        System.out.println("Characters: " + Char.characters);
        System.out.println("Weapons:    " + Weapon.weapons);
        System.out.println("Rooms:      " + Room.rooms);
        //Hard coded so it's faster. TODO change to inputs.
        int numChars = 2;
        int numComp = 1;
        //Create the players
        createPlayers(numChars, numComp);
        //Take all the cards, make a solution, deal the rest of the cards to the players
        makeSolutionAndDeal();
        //Print the solution for testing purposes TODO remove
        System.out.println("Solution:   " + solution);
        //Print the players for testing purposes TODO remove
        System.out.println("Players:    " + Player.players);

        //Begin screen printing
        Scanner scan = new Scanner(System.in);
        scan.nextLine();

        System.out.print(ConsoleCode.goTo(1, 1, true) + ConsoleCode.clearToEnd()); //Go to top left of screen and clear

        printBoard();

        scan.nextLine();
        System.out.print(ConsoleCode.goTo(1, 1, true) + ConsoleCode.clearToEnd()); //Go to top left of screen and clear

        printBoard();

        //put all characters visually on board
        for (Char chr: Char.characters){
            //TODO XY row col
            System.out.println(writeCharAtRowCol(chr.getHome().getX(), chr.getHome().getY(), chr));
        }

        scan.nextLine();

        System.out.println(blankTwoSpaces(0, 6) + `(1, 6, Char.getCharByAbbr("PE")));
        scan.nextLine();

        System.out.println("\33[0m");

        System.out.println(myBoard);


//        System.out.println("\33[25A\33[2K\33[1B\33[2K" + "This is so cool" + "\33[1B\33[2K");
//
//        scan.nextLine();
//        System.out.print("\33[1 1H\33[J");
//        for (String line : FileReader.parseFileAsListofLines("data/asciiboard.txt")) {
//            System.out.println(line);
//        }



    }
}


