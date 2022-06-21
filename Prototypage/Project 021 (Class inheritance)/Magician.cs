using UnityEngine;

[System.Serializable]
public class Magician : BeingAlive
{
    [SerializeField] protected int mana;

    // CTOR
    public Magician(string pName, int pHealth, int pMana):base(pName, pHealth)
    {
        mana = pMana;
    }

    // Debug.Log
    public void ConsoleLog()
    {
        Debug.Log("Name: " + name);
        Debug.Log("Health: " + health);
        Debug.Log("Mana: " + mana);
    }
}