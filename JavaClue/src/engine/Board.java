package engine;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Board class that stores the connections between squares and rooms.
 * It can provide the shortest route between locations
 * Created by Stephanie on 2/20/15.
 */
public class Board {
    int width;
    int height;
    ArrayList<Room> rooms = new ArrayList<>();
    ArrayList<ArrayList<Loc>> board = new ArrayList<>();
    HashMap<Loc, ArrayList<Loc>> boardDict = new HashMap<>();


    /**
     * Create a Clue board
     * @param width the width of the board
     * @param height the height of the board
     * @param rooms the list of rooms
     */
    public Board(int width, int height, ArrayList<Room> rooms) {
        this.width = width;
        this.height = height;
        this.rooms = rooms;
        //create empty nested list board
        for (int x = 0; x < this.width; x++) { //TODO XY Row Col
            board.add(new ArrayList<>());
            for (int y = 0; y < this.height; y++) {
                board.get(x).add(null);
            }
        }
        //add homespaces to board
        for (Char chr: Char.characters){
            boardDict.put(chr.getHome(), new ArrayList<>());
        }


//        ArrayList<ArrayList<String>> homeSpaces = FileReader.parseFileAsListofLists("data/homeSpaces.txt"); //open file homespaces
//        for (ArrayList<String> places : homeSpaces) {
//            int x = Integer.parseInt(places.get(0).trim());
//            int y = Integer.parseInt(places.get(1).trim());
//            boardDict.put(new Loc(x, y, places.get(2).trim(), null), new ArrayList<>());
//        }
        //add hallways
        ArrayList<ArrayList<String>> hallways = FileReader.parseFileAsListofLists("data/hallways.txt"); //open file hallways
        for (int x = 0; x < hallways.size(); x++) {
            for (String square : hallways.get(x)) {
                if (!square.trim().equals("")) {
                    int y = Integer.parseInt(square.trim());
                    boardDict.put(new Loc(x, y, "hallway", null), new ArrayList<>());
                }
            }
        }
        //add other hallways as references to hallways
        for (Loc node : boardDict.keySet()) {
            List<Loc> locList = Arrays.asList(new Loc(node.x, node.y + 1, "hallway", null), //TODO XY Row Col
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
        //add rooms
        for (Room room : Room.rooms){
            Loc thisRoom = new Loc (0, 0, room.name, room);
            boardDict.put(thisRoom, room.getDoorways());
            //System.out.println("Room to halls " + thisRoom + " " + boardDict.get(thisRoom));
            for (Loc hall : room.getDoorways()){
                boardDict.get(hall).add(thisRoom);
            }
        }

/**
        ArrayList<ArrayList<String>> roomList = FileReader.parseFileAsListofLists("data/rooms.txt");
        for (ArrayList<String> r : roomList) {
            Room myRoom = null;
            for (Room room : Room.rooms) {
                if (room.name.equals(r.get(0).trim())) {
                    myRoom = room; //gotcha!
                }
            }
            Loc thisRoom = new Loc(0, 0, r.get(0).trim(), myRoom);
            boardDict.put(thisRoom, new ArrayList<>());
            for (String coords : r.subList(1, r.size())) {
                coords = coords.replaceAll("[() ]", "");
                ArrayList<String> coordList = new ArrayList<>(Arrays.asList(coords.split(",")));
                int x = Integer.parseInt(coordList.get(0));
                int y = Integer.parseInt(coordList.get(1));
                boardDict.get(thisRoom).add(new Loc(x, y, "hallway", null));
            }
        }
        //add hallway references to rooms
        for (Room room : Room.rooms) {
            Loc tempRoom = new Loc(0, 0, room.name, room);
            for (Loc hallway : boardDict.get(tempRoom)) {
                boardDict.get(hallway).add(tempRoom);
            }

        }
 */


        //add passage references
        ArrayList<ArrayList<String>> passages = FileReader.parseFileAsListofLists("data/passages.txt");
        for (ArrayList<String> line : passages){
            String fromRoomName = line.get(0).trim();
            String toRoomName = line.get(1).trim();
            Room fromRoom = null;
            Room toRoom = null;
            for (Room room : Room.rooms) {
                if (room.name.equals(fromRoomName)) {
                    fromRoom = room; //gotcha!
                } else if (room.name.equals(toRoomName)) {
                    toRoom = room; //gotcha!
                }
            }
            Loc fromLoc = new Loc(0, 0, fromRoomName, fromRoom);
            Loc toLoc = new Loc(0, 0, toRoomName, toRoom);
            boardDict.get(fromLoc).add(toLoc);
        }
    }

    /**
<<<<<<< HEAD:JavaClue/src/engine/Board.java
     * Print out a list of spaces linked to a list of spaces it touches
     * @return aforementioned list in string form
=======
     * @return a string that tells (for every possible location) it's connecting squares
>>>>>>> origin/GraphicsSteph:JavaClue/src/Board.java
     */
    @Override
    public String toString() {
        String string = "";
        for (Object loc : boardDict.keySet().stream().filter(p -> p.name.contains("Home")).toArray()) {
            string = string + "\n" + (loc) + " connects to " + boardDict.get(loc);
        }
        return string;
    }

    /**
<<<<<<< HEAD:JavaClue/src/engine/Board.java
     * Find the shortest path between two spaces
     * @param start the space you're on
     * @param end the space you want to go to
     * @return a list of locations connecting start and end
=======
     * Performs a breadth first search to determine the best way to get from one location to another
     * To be used for players determining the fastest route between rooms
     * @param start where are you (the player) right now
     * @param end where do you want to go?
     * @return what the shortest (legal) path is (null is returned if no path is found)
     *
>>>>>>> origin/GraphicsSteph:JavaClue/src/Board.java
     */
    public ArrayList<Loc> bfs(Loc start, Loc end) {
        ArrayList<ArrayList<Loc>> queue = new ArrayList<>();
        queue.add(new ArrayList<>(Arrays.asList(start)));
        ArrayList<Loc> path;
        while (!queue.isEmpty()){
            path = queue.remove(0);
            Loc node = path.get(path.size());
            if (node.equals(end)){
                return path;
            }
            for (Loc adjacent : boardDict.get(node)){
                if (!path.contains(adjacent)){
                    ArrayList<Loc> newPath = path;
                    newPath.add(adjacent);
                    queue.add(newPath);
                }
            }
        }
        return null;
    }
}