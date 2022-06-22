using UnityEngine;

[System.Serializable]
public struct Inventory
{
    public Armors[] myArmors;
    public Weapons[] myWeapons;
    
    // Print Inventory
    public void PrintInventory()
    {
        if(myArmors.Length > 0 || myWeapons.Length > 0)
        {
            for(int i = 0; i < myArmors.Length; i++)
            {
                myArmors[i].PrintArmorStats();
            }

            for(int i = 0; i < myWeapons.Length; i++)
            {
                myWeapons[i].PrintWeaponStats();
            }
        }
    }
}