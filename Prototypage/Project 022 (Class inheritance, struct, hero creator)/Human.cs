using UnityEngine;

public class Human
{
    [SerializeField] protected string name;

    // CTOR
    public Human(string pName)
    {
        name = pName;
    }

    // Get name
    public string GetName()
    {
        return(name);
    }
}