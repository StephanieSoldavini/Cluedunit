package engine;

import java.util.ArrayList;

/**
 * Room cards
 * Created by Stephanie on 2/16/15.
 */
public class Room extends Card {

    public static ArrayList<Room> rooms = new ArrayList<>();

    public ArrayList<Loc> getDoorways() {
        return doorways;
    }

    private ArrayList<Loc> doorways = new ArrayList<>();

    public Room(String name, ArrayList<Loc> doorways) {

        super(name);
        Room.rooms.add(this);
        this.doorways = doorways;
    }

    @Override
    public String toString() {
        return "The " + this.name;
    }
}
