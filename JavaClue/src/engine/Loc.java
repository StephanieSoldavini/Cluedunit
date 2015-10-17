package engine;

/**
 * Class to describe locations (both room and hallway)
 * Created by Stephanie on 2/16/15.
 */
public class Loc {
    Room room;
    String name;
    int x; //col
    int y; //row

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    /**
     * @param x in terms of spaces, where 0 is left and increases as you move right
     * @param y 0 is top and increases downward
     * @param name what is this called (Ballroom, hallway, lounge, etc.)
     * @param room Room object. Null if hallway
     */
    public Loc(int x, int y, String name, Room room) {
        this.x = x;
        this.y = y;
        this.name = name;
        this.room = room;
    }

    @Override
    public int hashCode() {
        int result = room != null ? room.hashCode() : 0;
        result = 31 * result + x;
        result = 31 * result + y;
        return result;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Loc loc = (Loc) o;

        if (this.x != loc.x) return false;
        if (this.y != loc.y) return false;
        if (name != null ? !name.equals(loc.name) : loc.name != null) return false;
        if (this.room != null && !this.room.equals(loc.room)) return false;

        return true;
    }

    @Override
    public String toString() {
        String printname = "";
        if (room!= null) printname = room.toString();
        else printname = name + " at (" + y + ", " + x + ")";
        return "engine.Loc{" + printname + "}";
    }
}
