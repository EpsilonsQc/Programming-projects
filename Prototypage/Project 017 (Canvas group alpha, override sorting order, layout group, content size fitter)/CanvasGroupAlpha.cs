using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class CanvasGroupAlpha : MonoBehaviour
{
    [SerializeField] CanvasGroup myCanvasGroup;
    [SerializeField] float myTimer = 2f;
    [SerializeField] float t;

    void Awake()
    {
        myCanvasGroup = gameObject.GetComponent<CanvasGroup>();
    }

    void Update()
    {
        // With PingPong
        // myCanvasGroup.alpha = (Mathf.PingPong(Time.time / myTimer, 1));

        // With Lerp
        t += myTimer * Time.deltaTime;
        myCanvasGroup.alpha = Mathf.Lerp(1, 0 , t);
    }
}
