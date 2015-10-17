package engine;

import java.util.ArrayList;

/**
 * Weapon cards
 * Created by Stephanie on 2/16/15.
 */

public class Weapon extends Card {
    public static ArrayList<Weapon> weapons = new ArrayList<>();
    private Room location;

    /**
     * Adds weapons to static arraylist
     * @param name what is it called
     * @param location what room is the weapon in
     */
    public Weapon(String name, Room location) {
        super(name);
        this.location = location;
        Weapon.weapons.add(this);
    }

    @Override
    public String toString() {
        return "The " + this.name;
    }
}

