import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

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
//        System.out.println(Char.characters);
//        System.out.println(tempChars);
//        System.out.println(Weapon.weapons);
//        System.out.println(tempWeaps);
//        System.out.println(Room.rooms);
//        System.out.println(tempRooms);
//        System.out.println(solution);
    }

    public static void main(String[] args) {
        Card.createAllCards();
        new Board(24, 25, Room.rooms);
        System.out.println("Characters: " + Char.characters);
        System.out.println("Weapons:    " + Weapon.weapons);
        System.out.println("Rooms:      " + Room.rooms);
        int numChars = 6;
        int numComp = 3;
        Player.createPlayers(numChars, numComp);
        makeSolutionAndDeal();
        System.out.println("Solution:   " + solution);
        System.out.println("Players:    " + Player.players);
    }
}


