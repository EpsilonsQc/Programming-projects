using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class DestroySelf : MonoBehaviour
{
    [SerializeField] public TextMeshProUGUI price;

    public void Destroy()
        {
            string currentPrice = price.text;
            int currentPriceInt = int.Parse(currentPrice);
            
            MenuController.totalPrice = MenuController.totalPrice - currentPriceInt;
            MenuController.totalCost.text = MenuController.totalPrice.ToString();

            MenuController.instanceCount = MenuController.instanceCount - 1;

            Destroy(gameObject);
        }
}