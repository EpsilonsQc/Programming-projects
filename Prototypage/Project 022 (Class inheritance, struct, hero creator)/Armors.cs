using UnityEngine;

[System.Serializable]
public struct Armors
{
    [SerializeField] private string name;
    [SerializeField] private int defense;
    [SerializeField] private int durability;

    // Armors CTOR
    public Armors(string wName, int wDefense, int wDurability)
    {
        name = wName;
        defense = wDefense;
        durability = wDurability;
    }

    // Print Armor Stats
    public void PrintArmorStats()
    {
        Debug.LogFormat("Armor name : {0} - Defense : {1} - Durability : {2}", name, defense, durability);
    }

    // Get Name
    public string GetArmorName()
    {
        return(name);
    }

    // Get Defense
    public int GetArmorDefense()
    {
        return(defense);
    }

    // Get Durability
    public int GetArmorDurability()
    {
        return(durability);
    }
}