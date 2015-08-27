package engine;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Stephanie on 2/16/15.
 */
public class Player {
    public static Random rand = new Random();
    private ArrayList<Card> cards;
    private final boolean human;
    private final String name;
    private final Char character;
    private final int order;
    private Loc location;
    public static ArrayList<Player> players = new ArrayList<>();

    public Player (String name, Char character, boolean human, int order, Loc location, ArrayList<Card> cards) {
        this.name = name;
        this.character = character;
        this.human = human;
        this.order = order;
        this.location = location;
        this.cards = cards;
        Player.players.add(this);
    }



    public void addCard(Card card){
        this.cards.add(card);
    }

    @Override
    public String toString() {
        if (this.character == null){
            return this.name;
        } else {return this.name + " as " + this.character.name;}
    }

    public void move(int spaces, Room destination) {
        boolean inNewRoom = false;

        while (spaces > 0 && !inNewRoom) {
            if (Room.rooms.contains(location.room)) {
                /**
                 * You are in a room
                 * Pick a door closest to destination
                 * Move out of that door
                 */
            }
        }
    }



}
