import java.io.*;
import java.util.*;

class Flower {
    String whatsYourName() {
        return "I have many names and types.";
    }
}

class Jasmine extends Flower {
    String whatsYourName() {
        return "Jasmine";
    }
}

class Lotus extends Flower {
    String whatsYourName() {
        return "Lotus";
    }
}

class Lily extends Flower {
    String whatsYourName() {
        return "Lily";
    }
}

class State {
    Flower yourNationalFlower() {
        return new Flower();
    }
}

class WestBengal extends State {
    @Override
    Jasmine yourNationalFlower() {
        return new Jasmine();
    }
}

class Karnataka extends State {
    @Override
    Lotus yourNationalFlower() {
        return new Lotus();
    }
}

class AndhraPradesh extends State {
    @Override
    Lily yourNationalFlower() {
        return new Lily();
    }
}


public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String stateName = br.readLine().trim();
        State state;
        
        if (stateName.equals("WestBengal")) {
            state = new WestBengal();
        } else if (stateName.equals("Karnataka")) {
            state = new Karnataka();
        } else if (stateName.equals("AndhraPradesh")) {
            state = new AndhraPradesh();
        } else {
            state = new State();
        }
        
        Flower flower = state.yourNationalFlower();
        System.out.println(flower.whatsYourName());
    }
}
