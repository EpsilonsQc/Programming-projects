using UnityEngine;

[System.Serializable]
public struct Weapons
{
    [SerializeField] private string name;
    [SerializeField] private int damage;

    // Weapons CTOR
    public Weapons(string aName, int aDamage)
    {
        name = aName;
        damage = aDamage;
    }

    // Print Weapon Stats
    public void PrintWeaponStats()
    {
        Debug.LogFormat("Weapon name : {0} - Damage : {1}", name, damage);
    }

    // Get Weapon Name
    public string GetWeaponName()
    {
        return(name);
    }

    // Get Weapon Damage
    public int GetWeaponDamage()
    {
        return(damage);
    }
}