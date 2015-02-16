/**
 * Created by Stephanie on 2/16/15.
 */
public class Weapon extends Card {
    private Room location;
    public Weapon(String name, Room location) {
        super(name);
        this.location = location;
    }
}
