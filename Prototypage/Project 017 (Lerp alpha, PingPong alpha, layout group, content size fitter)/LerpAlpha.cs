using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LerpAlpha : MonoBehaviour
{
    [SerializeField] CanvasGroup myCanvasGroup;
    [SerializeField] float myTimer = 2f;
    [SerializeField] float interpolationRatio;

    void Awake()
    {
        myCanvasGroup = gameObject.GetComponent<CanvasGroup>();
    }

    void Update()
    {
        interpolationRatio += myTimer * Time.deltaTime;
        myCanvasGroup.alpha = Mathf.Lerp(1, 0 , interpolationRatio);
    }
}