
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Side;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.scene.text.TextBuilder;
import javafx.stage.Stage;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.AnchorPane;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import sun.plugin.javascript.navig.Anchor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;

/**
 * Main GUI class written with javafx
 */
public class BorderPaneClue extends Application {
    private final Image BOARD = new Image(getClass().getResourceAsStream("/Image/ScanBoardSmall.jpg"));
    private final Image LOGO = new Image(getClass().getResourceAsStream("/Image/Clue.png"));
    private int boardWidth = 1200;
    private int boardHeight = 800;
    private int buttonHeight = 50;
    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setResizable(true);
        primaryStage.setScene(new Scene(root, boardWidth, boardHeight));

        primaryStage.setTitle("Clue");
        primaryStage.getIcons().add(new Image(getClass().getResourceAsStream("Image/Pieces/scarletpawn.png")));

        BorderPane borderPane = new BorderPane();

//        //Top content
//        Rectangle topRectangle = new Rectangle(400, 23, Color.DARKSEAGREEN);
//        topRectangle.setStroke(Color.BLACK);
//        borderPane.setTop(topRectangle);

//        //Left content
//        Label label1 = new Label("Left hand");
//        Label label2 = new Label("Choice One");
//        Label label3 = new Label("Choice Two");
//        Label label4 = new Label("Choice Three");
//        VBox leftVbox = new VBox();
//        leftVbox.getChildren().addAll(label1, label2, label3, label4);
//        borderPane.setLeft(leftVbox);

        //Right content
        //Label rightlabel1 = new Label("This is where the CLUE logo should go");
        ImageView logoImage = new ImageView(LOGO);

        logoImage.setFitWidth(primaryStage.getScene().getWidth() * (.25));
        logoImage.setPreserveRatio(true);

        Button move = new Button("Move");
        Button suggest = new Button("Suggest");

        ImageView gearImage = new ImageView(new Image(getClass().getResourceAsStream("/Image/gear3.png")));
        System.out.println();

        Button settings = new Button("",gearImage);
        HBox actions = new HBox();
        move.setPrefSize(100, buttonHeight);
        suggest.setPrefSize(100, buttonHeight);
        settings.setPrefSize(buttonHeight, buttonHeight);
        System.out.println(suggest.getPrefHeight());
        gearImage.setFitHeight(suggest.getPrefHeight() * .5);
        gearImage.setPreserveRatio(true);
        gearImage.setSmooth(true);
        actions.setSpacing(10);
        actions.setPadding(new Insets(10, 20, 10, 20));
        actions.getChildren().addAll(move, suggest, settings);


        //Label rightlabel2 = new Label("This is where the event tracker will go");

        final ListView<String> listView = new ListView<String>();
        listView.setItems(FXCollections.observableArrayList(
                "this", "is", "where", "the", "event", "tracker", "will", "go",
                "PlayerX suspects ___ with ___ in the ___. PlayerZ showed them a card",
                "PlayerY took the secret passage to ___."
        ));
        //ArrayList<String> events = new ArrayList<>(Arrays.asList("this", "is", "where", "the", "event", "tracker", "will", "go",
        //        "PlayerX suspects ___ with ___ in the ___. PlayerZ showed them a card",
        //        "PlayerY took the secret passage to ___."));

        //Collection<Text> wrapEvents = new ArrayList<>();
        //events.forEach((event) -> wrapEvents.add(TextBuilder.create().text(event).wrappingWidth(200).build()));


        //listView.getItems().addAll(wrapEvents);

        //listView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
        //listView.setFixedCellSize((double) 200);
        listView.setMaxWidth(primaryStage.getScene().getWidth() * (.25));
        listView.setMinWidth(primaryStage.getScene().getWidth() * (.25));

        VBox rightVbox = new VBox();

        rightVbox.getChildren().addAll(logoImage, actions, listView);
        borderPane.setRight(rightVbox);

        //Center content

        AnchorPane boardBox = new AnchorPane();
        ImageView board = new ImageView(BOARD);
        board.setFitHeight(primaryStage.getScene().getHeight() * (.75));
        board.setPreserveRatio(true);
        boardBox.getChildren().add(board);

        TabPane tabPane = new TabPane();
        tabPane.setSide(Side.TOP);
        tabPane.setTabClosingPolicy(TabPane.TabClosingPolicy.UNAVAILABLE);

        final Tab boardTab = new Tab();
        boardTab.setText("engine.Board");
        boardTab.setContent(boardBox);
        final Tab notesTab = new Tab();
        notesTab.setText("Notes");
        notesTab.setContent(new Label("Notey note notes"));
        tabPane.getTabs().addAll(boardTab, notesTab);

        VBox centerBox = new VBox();
        centerBox.getChildren().addAll(tabPane);
        borderPane.setCenter(centerBox);

        //Bottom content
        Label bottomLabel = new Label("This is where the cards will go");
        BorderPane.setAlignment(bottomLabel, Pos.BOTTOM_CENTER);
        borderPane.setBottom(bottomLabel);

        root.getChildren().add(borderPane);
    }

    public double getSampleWidth() { return boardWidth; }

    public double getSampleHeight() { return boardHeight; }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}