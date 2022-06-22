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
        Debug.LogFormat("Heroes name : {0} - Health : {1} - Mana : {2}", name, health, mana);
    }
}