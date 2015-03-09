import java.io.File;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Created by Stephanie on 2/20/15.
 */
public class Board {
    int width;
    int height;
    ArrayList<Room> rooms = new ArrayList<>();
    ArrayList<ArrayList<Loc>> board = new ArrayList<>();
    HashMap<Loc, ArrayList<Loc>> boardDict = new HashMap<>();


    public Board(int width, int height, ArrayList<Room> rooms) {
        this.width = width;
        this.height = height;
        this.rooms = rooms;
        //create empty nested list board
        for (int x = 0; x < this.width; x++) {
            board.add(new ArrayList<>());
            for (int y = 0; y < this.height; y++) {
                board.get(x).add(null);
            }
        }
        //add to board
        ArrayList<ArrayList<String>> homeSpaces = FileReader.parseFileAsList("data/homeSpaces.txt"); //open file homespaces
        for (ArrayList<String> places : homeSpaces) {
            int x = Integer.parseInt(places.get(0).trim());
            int y = Integer.parseInt(places.get(1).trim());
            boardDict.put(new Loc(x, y, places.get(2).trim(), null), new ArrayList<>());
        }

        ArrayList<ArrayList<String>> hallways = FileReader.parseFileAsList("data/hallways.txt"); //open file hallways
        for (int x = 0; x < hallways.size(); x++) {
            for (String square : hallways.get(x)) {
                if (!square.trim().equals("")) {
                    int y = Integer.parseInt(square.trim());
                    boardDict.put(new Loc(x, y, "hallway", null), new ArrayList<>());
                }
            }
        }

        for (Loc node : boardDict.keySet()) {
            List<Loc> locList = Arrays.asList(new Loc(node.x, node.y + 1, "hallway", null),
                    new Loc(node.x, node.y - 1, "hallway", null),
                    new Loc(node.x + 1, node.y, "hallway", null),
                    new Loc(node.x - 1, node.y, "hallway", null));
            for (Loc b : locList) {

                if (boardDict.containsKey(b)) {
                    ArrayList<Loc> tempList = boardDict.get(node);
                    tempList.add(b);
                    boardDict.put(node, tempList);
                }
            }
        }

        ArrayList<ArrayList<String>> roomList = FileReader.parseFileAsList("data/rooms.txt");
        for (ArrayList<String> r : roomList){
            Room myRoom = null;
            for (Room room : Room.rooms) {
                if (room.name.equals(r.get(0).trim())) {
                    myRoom = room; //gotcha!
                }
            }
            Loc thisRoom = new Loc(0,0,r.get(0).trim(),myRoom);
            boardDict.put(thisRoom, new ArrayList<>());
            for (String coords : r.subList(1,r.size())){
                coords = coords.replaceAll("[() ]", "");
                ArrayList<String> coordList = new ArrayList<>(Arrays.asList(coords.split(",")));
                int x = Integer.parseInt(coordList.get(0));
                int y = Integer.parseInt(coordList.get(1));
                boardDict.get(thisRoom).add(new Loc(x, y, "hallway", null));
            }
        }
        for (Room room : Room.rooms){
            Loc tempRoom = new Loc(0,0,room.name,room);
            for (Loc hallway : boardDict.get(tempRoom)){
                boardDict.get(hallway).add(tempRoom);
            }
        }
        Loc study        = new Loc(0,0,"Study",new Room("Study"));
        Loc kitchen      = new Loc(0,0,"Kitchen",new Room("Kitchen"));
        Loc conservatory = new Loc(0,0,"Conservatory",new Room("Conservatory"));
        Loc lounge       = new Loc(0,0,"Lounge",new Room("Lounge"));





    }


    @Override
    public String toString(){
        String string = new String();
        for (Loc loc : boardDict.keySet()) {
            string = string + "\n" + (loc) + " connects to " + boardDict.get(loc);
        }
        return string;
    }

}
