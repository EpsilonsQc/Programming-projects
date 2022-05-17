using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class ScaleModifier : MonoBehaviour
{
    public int setScaleOnDisable = 1;

    void OnEnable()
    {
        RandomizeScale(); // OnEnable, randomize scale
    }

    void OnDisable()
    {
        ChangeScale(); // OnDisable, set a scale defined by the inspector
    }

    public void ChangeScale()
    {
        gameObject.transform.localScale = new Vector3(setScaleOnDisable, setScaleOnDisable, setScaleOnDisable);
    }

    public void RandomizeScale()
    {
        gameObject.transform.localScale = new Vector3(Random.Range(1, 10), Random.Range(1, 10), Random.Range(1, 10));
    }
}