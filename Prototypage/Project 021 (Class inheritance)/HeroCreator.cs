using UnityEngine;

public class HeroCreator : MonoBehaviour
{
    [Header("OBJECTS")]
    [SerializeField] private Magician magicianObj1;
    [SerializeField] private Magician magicianObj2;
    [SerializeField] private Magician[] magicianObjArray;

    void Awake()
    {
        magicianObj1 =  new Magician("Epsilons", 250, 100); // Initialize my magicianObj1 : Name, Health, Mana
        magicianObj1.ConsoleLog(); // Epsilons, 250, 100

        magicianObj2.ConsoleLog(); // NULL, 0 , 0

        magicianObjArray[0] = new Magician("Array", 250, 100);
        magicianObjArray[0].ConsoleLog(); // Array, 250, 100
    }
}