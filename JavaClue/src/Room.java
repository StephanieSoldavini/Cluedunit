import java.util.ArrayList;

/**
 * Room cards
 * Created by Stephanie on 2/16/15.
 */
public class Room extends Card {
    public static ArrayList<Room> rooms = new ArrayList<>();

    /**
     * Adds room objects to static array
     * @param name name of room
     */
    public Room(String name) {
        super(name);
        Room.rooms.add(this);
    }

    @Override
    public String toString() {
        return "The " + this.name;
    }
}
