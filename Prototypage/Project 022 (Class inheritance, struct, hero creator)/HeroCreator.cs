using UnityEngine;

public class HeroCreator : MonoBehaviour
{
    [Header("OBJECTS")]
    [SerializeField] private Magician[] myMagicians;

    void Awake()
    {
        myMagicians = new Magician[1];
        myMagicians[0] = new Magician("Akarias", 250, 100); // Name, Health, Mana
        myMagicians[0].ConsoleLog(); // Name, Health, Mana + PrintInventory()
    }
}