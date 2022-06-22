using UnityEngine;

public class BeingAlive : Human
{
    [SerializeField] protected int health;

    // CTOR
    public BeingAlive(string pName, int pHealth):base(pName)
    {
        health = pHealth;
    }

    // Get health
    public int GetHealth()
    {
        return(health);
    }
}