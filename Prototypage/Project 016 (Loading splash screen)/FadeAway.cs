using System.Collections; 
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class FadeAway : MonoBehaviour
{
    [SerializeField] RawImage rImage;
    [SerializeField] float startTime;
    [SerializeField] float waitFor = 2f; // Black screen waits [amount of] seconds before gradually fading away;
    [SerializeField] float fadeSpeed = 0.15f;

    void Start()
    {
        rImage = gameObject.GetComponent<RawImage>();
        startTime = Time.time + waitFor;
    }

    void Update()
    {
        rImage.color = Color.Lerp(Color.black, Color.clear, (Time.time - startTime) * fadeSpeed);

        if(rImage.color == Color.clear)
        {
            gameObject.SetActive(false);
        }
    }
}
