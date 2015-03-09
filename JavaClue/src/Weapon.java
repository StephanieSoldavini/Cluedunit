import java.util.ArrayList;

/**
 * Created by Stephanie on 2/16/15.
 */

public class Weapon extends Card {
    public static ArrayList<Weapon> weapons = new ArrayList<>();
    private Room location;
    public Weapon(String name, Room location) {
        super(name);
        this.location = location;
        Weapon.weapons.add(this);
    }
}
