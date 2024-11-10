abstract class Shape {
    abstract public void numberOfSides();
}

class Rectangle extends Shape {
    public void numberOfSides() {
        System.out.println("Number of sides of a Rectangle = 4");
    }
}

class Triangle extends Shape {
    public void numberOfSides() {
        System.out.println("Number of sides of a Triangle = 3");
    }
}

class Hexagon extends Shape {
    public void numberOfSides() {
        System.out.println("Number of sides of a Hexagon = 6");
    }
}

class ShapeTest {
    public static void main(String[] args) {
        Shape S = new Rectangle();
        S.numberOfSides();
        S = new Triangle();
        S.numberOfSides();
        S = new Hexagon();
        S.numberOfSides();
    }
}
