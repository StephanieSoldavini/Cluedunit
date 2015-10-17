import java.util.ArrayList;

/**
 * All character cards
 * Created by Stephanie on 2/16/15.
 */
public class Char extends Card {
    public static ArrayList<Char> characters = new ArrayList<>();
    String abbr;
    String color;

    /**
     * Adds the card to a static arraylist of character cards
     * @param name name of person
     * @param abbr shorthand for the person (may delete with gui addition)
     * @param color what color is this person
     */
    public Char(String name, String abbr, String color) {
        super(name);
        this.abbr = abbr;
        this.color = color;
        Char.characters.add(this);
    }

    @Override
    public String toString() {
        return this.name;
    }

}
