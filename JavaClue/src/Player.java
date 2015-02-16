/**
 * Created by Stephanie on 2/16/15.
 */
public class Player {
    private String name;
    private Char character;
    private int order;
    private Room location;

    public Player (String name, Char character, int order, Room location) {
        this.name = name;
        this.character = character;
        this.order = order;
        this.location = location;
    }
}
