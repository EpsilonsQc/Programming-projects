using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class MenuController : MonoBehaviour
{
    [Header("GAME OBJECTS")]
    [SerializeField] private GameObject template; // prefab
    [SerializeField] private GameObject inventory; // inventory parent
    [SerializeField] private SpriteRenderer spriteRenderer;
    [Space(10)]

    [Header("RESOURCES")]
    [SerializeField] private Sprite[] sprites;

    [Header("TEXT FIELDS")] 
    [SerializeField] private TextMeshProUGUI  objectName;
    [SerializeField] private TextMeshProUGUI  price;
    [SerializeField] static public TextMeshProUGUI  totalCost;

    static public int instanceCount = 0;

    private int minPrice = 5;
    private int maxPrice = 250;
    private int actualPrice = 0;
    private string actualPriceString = "";
    static public int totalPrice = 0;

    private int minSprites = 0;
    private int maxSprites = 21;
    private int currentSprites = 0;

    void Awake()
    {
        template = GameObject.Find("template");
        inventory = GameObject.Find("Canvas/img_inventory");
        spriteRenderer = GameObject.Find("template/button/sprite_renderer").GetComponent<SpriteRenderer>();
        sprites = Resources.LoadAll<Sprite>("");

        objectName = GameObject.Find("template/button/text_object_name").GetComponent<TextMeshProUGUI>();
        price = GameObject.Find("template/button/text_price").GetComponent<TextMeshProUGUI>();
        totalCost = GameObject.Find("img_total_cost/text_total_cost").GetComponent<TextMeshProUGUI>();
    }

    public void AddRandomItem()
    {
        if(instanceCount <= 7)
        {
            instanceCount++;

            currentSprites = Random.Range(minSprites, maxSprites);
            spriteRenderer.sprite = sprites[currentSprites];

            objectName.text = spriteRenderer.sprite.name;

            actualPrice = Random.Range(minPrice, maxPrice);
            actualPriceString = actualPrice.ToString();
            price.text =  actualPrice.ToString();

            totalPrice = totalPrice + actualPrice;

            totalCost.text = totalPrice.ToString();

            GameObject clone = Instantiate(template, transform.parent = inventory.transform);
            clone.name = "clone";
        }
    }
}