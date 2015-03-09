public class Main {

    public static void main(String[] args) {
        Card.createAllCards();
        System.out.println(new Board(24, 25, Room.rooms));
        System.out.println("Characters: " + Char.characters);
        System.out.println("Weapons:    " + Weapon.weapons);
        System.out.println("Rooms:      " + Room.rooms);
    }
}


