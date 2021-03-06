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
    [SerializeField] private TextMeshProUGUI objectName;
    [SerializeField] private TextMeshProUGUI price;
    [SerializeField] static public TextMeshProUGUI totalCost;

    static public int instanceCount = 0;

    private int minPrice = 1;
    private int maxPrice = 2500;
    private int actualPrice = 0;
    static public int totalPrice = 0;

    private int minSprites = 0;
    private int maxSprites = 21;
    private int currentSprites = 0;

    void Awake()
    {
        template = GameObject.Find("Canvas/template");
        inventory = GameObject.Find("Canvas/img_inventory");
        spriteRenderer = GameObject.Find("Canvas/template/sprite_renderer").GetComponent<SpriteRenderer>();
        sprites = Resources.LoadAll<Sprite>("");

        objectName = GameObject.Find("template/button/text_object_name").GetComponent<TextMeshProUGUI>();
        price = GameObject.Find("template/button/text_price_group/text_price").GetComponent<TextMeshProUGUI>();
        totalCost = GameObject.Find("btn_total_cost/text_total_cost").GetComponent<TextMeshProUGUI>();
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
            price.text =  actualPrice.ToString();

            totalPrice = totalPrice + actualPrice;
            totalCost.text = totalPrice.ToString();

            GameObject clone = Instantiate(template);
            clone.SetActive(true);
            clone.transform.SetParent(inventory.transform, false);
            clone.name = spriteRenderer.sprite.name + " (" + actualPrice.ToString() + "$)";
        }
    }
}