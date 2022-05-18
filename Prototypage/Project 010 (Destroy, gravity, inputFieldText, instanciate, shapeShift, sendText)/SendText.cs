using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SendText : MonoBehaviour
{
    [SerializeField] Text MyText;

    public void SendTextF() // public function
    {
        MyText.text = "Let's change some text..."; 
    }
}