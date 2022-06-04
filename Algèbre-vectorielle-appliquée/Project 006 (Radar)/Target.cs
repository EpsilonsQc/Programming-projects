using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using MyDebug;

public enum RelativeDirection
{
    FrontLeft,
    FrontRight,
    RearLeft,
    RearRight
}

public class Target
{
    private GameObject goTarget = null;
    private Vector2 position = new Vector2();
    private Color color = Color.white;

    public Target() 
    { 
        setPosition(Vector2.zero); 
    }

    public Vector2 getPosition() 
    {
        return position;
    }

    public void setPosition(Vector2 newPos)
    {
        position = newPos;
    }

    public void setColor(Color newColor)
    {
        if (goTarget != null) 
        {
            goTarget.GetComponent<LineRenderer>().material.color = newColor;
        }
    }

    // Définir la bonne couleur en fonction de la direction
    public void SetMyRelativeDirection(RelativeDirection direction)
    {        
        switch(direction)
        {
        case RelativeDirection.FrontLeft:
            color = Color.green;
            break;
        case RelativeDirection.FrontRight:
            color = Color.blue;
            break;
        case RelativeDirection.RearLeft:
            color = Color.yellow;
            break;
        case RelativeDirection.RearRight:
            color = Color.magenta;
            break;
        }

        setColor(color);
    }

    public void Draw(Vector2 newPosition) 
    {
        if (goTarget == null) 
        {
            goTarget = Point.DrawNewPoint(newPosition, 3f, color);
        }
        else 
        {
            setColor(color);
        }
        setPosition(newPosition);
    }
}