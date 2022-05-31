using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ColorLerp : MonoBehaviour
{
    private RawImage rImage;
    private float startTime;
    private float fadeSpeed = 0.25f;

    void Start()
    {
        rImage = gameObject.GetComponent<RawImage>();
        startTime = Time.time;
    }

    void Update()
    {
        rImage.color = Color.Lerp(Color.black, Color.clear, (Time.time - startTime) * fadeSpeed);
    }
}