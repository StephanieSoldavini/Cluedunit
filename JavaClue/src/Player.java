/**
 * Created by Stephanie on 2/16/15.
 */
public class Player {
    private String name;
    private Char character;
    private int order;
    private Loc location;

    public Player (String name, Char character, int order, Loc location) {
        this.name = name;
        this.character = character;
        this.order = order;
        this.location = location;
    }

    @Override
    public String toString() {
        return this.character.name;
    }

    public void move(int spaces, Room destination) {
        boolean inNewRoom = false;

        while (spaces > 0 && inNewRoom == false) {
            if (Room.rooms.contains(location)) {
                /**
                 * You are in a room
                 * Pick a door closest to destination
                 * Move out of that door
                 */
            }
        }

    }

}
