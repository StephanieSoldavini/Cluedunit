/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.AnchorPane;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

/**
 * An example of  a BorderPane layout, with placement of children in the top,
 * left, center, right, and bottom positions.
 *
 * @see javafx.scene.layout.BorderPane
 * @related controls/text/SimpleLabel
 * @related graphics/images/ImageCreationSample
 */
public class BorderPaneClue extends Application {
    private final Image BOARD = new Image(getClass().getResourceAsStream("/Image/ScanBoardSmall.jpg"));
    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setResizable(true);
        primaryStage.setScene(new Scene(root, 800, 800));
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
        Label rightlabel1 = new Label("This is where the CLUE logo should go");

        Button move = new Button("Move");
        Button suggest = new Button("Suggest");
        HBox actions = new HBox();
        actions.setSpacing(10);
        actions.setPadding(new Insets(10, 20, 10, 20));
        actions.getChildren().addAll(move, suggest);


        Label rightlabel2 = new Label("This is where the event tracker will go");

        final ListView<String> listView = new ListView<String>();
        listView.setItems(FXCollections.observableArrayList(
                "Row 1", "Row 2", "Long Row 3", "Row 4", "Row 5", "Row 6",
                "Row 7", "Row 8", "Row 9", "Row 10", "Row 11", "Row 12", "Row 13",
                "Row 14", "Row 15", "Row 16", "Row 17", "Row 18", "Row 19", "Row 20"
        ));
        //listView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);


        Label rightlabel3 = new Label("blah");
        VBox rightVbox = new VBox();

        //rightVbox.setAlignment(Pos.BASELINE_RIGHT);
        rightVbox.getChildren().addAll(rightlabel1, actions, rightlabel2, listView, rightlabel3);
        borderPane.setRight(rightVbox);

        //Center content
        Label centerLabel = new Label("This is where the board will go");
        ImageView board = new ImageView(BOARD);

        //Using AnchorPane only to position items in the center
//        AnchorPane centerAP = new AnchorPane();
//        AnchorPane.setTopAnchor(centerLabel, (double) 5);
//        AnchorPane.setLeftAnchor(centerLabel, (double) 20);
//        //AnchorPane.setTopAnchor(imageView, Double.valueOf(40));
//        //AnchorPane.setLeftAnchor(imageView, Double.valueOf(30));
//        centerAP.getChildren().addAll(centerLabel);
        HBox centerBox = new HBox();
        centerBox.getChildren().addAll(centerLabel, board);
        borderPane.setCenter(centerBox);

        //Bottom content
        Label bottomLabel = new Label("This is where the cards will go");
        BorderPane.setAlignment(bottomLabel, Pos.BOTTOM_CENTER);
        borderPane.setBottom(bottomLabel);

        root.getChildren().add(borderPane);
    }

    public double getSampleWidth() { return 400; }

    public double getSampleHeight() { return 400; }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}