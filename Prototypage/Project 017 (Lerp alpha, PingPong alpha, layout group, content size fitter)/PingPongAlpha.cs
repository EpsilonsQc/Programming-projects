using System.Collections;
using System.Collections.Generic;
using UnityEngine; 

public class PingPongAlpha : MonoBehaviour
{
    [SerializeField] CanvasGroup myCanvasGroup;
    [SerializeField] float myTimer = 2f;
    [SerializeField] float length;

    void Awake()
    {
        myCanvasGroup = gameObject.GetComponent<CanvasGroup>();
        length = 1f;
    }

    void Update()
    {
        // With PingPong
        myCanvasGroup.alpha = (Mathf.PingPong(Time.time / myTimer, length));
    }
}
