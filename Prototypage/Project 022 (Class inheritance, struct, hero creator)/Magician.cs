using UnityEngine;

[System.Serializable] 
public class Magician : BeingAlive
{
    [SerializeField] protected int mana;
    [SerializeField] private Inventory myInventory;

    // Magician CTOR
    public Magician(string pName, int pHealth, int pMana):base(pName, pHealth)
    {
        mana = pMana;

        myInventory.myArmors = new Armors[1];
        myInventory.myArmors[0] =  new Armors("Shimmering White Robe", 10, 100); // name, defense, durability

        myInventory.myWeapons = new Weapons[1];
        myInventory.myWeapons[0]= new Weapons("Rusted Dirk", 2); // name , damage
    }

    // Get mana
    public int GetMana()
    {
        return(mana);
    }

    // Get Inventory
    public Inventory GetInventory()
    {
        return(myInventory);
    }

    // Debug.Log
    public void ConsoleLog()
    {
        Debug.LogFormat("Heroes name : {0} - Health : {1} - Mana : {2}", name, health, mana);
        myInventory.PrintInventory();
    }
}