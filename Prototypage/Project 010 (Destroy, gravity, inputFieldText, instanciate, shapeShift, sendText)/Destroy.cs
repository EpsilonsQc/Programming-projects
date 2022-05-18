using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Destroy : MonoBehaviour
{
    [Header("ON/OFF")]
    [SerializeField] private bool debugBreak;
    [SerializeField] private bool destroyScriptInstance;
    [SerializeField] private bool destroyObject;
    [SerializeField] private bool destroyObjectPlane;
    [SerializeField] private bool destroyShapeShiftScript;
    [Space(15)]
    [Header("GAMEOBJECT")]
    [SerializeField] GameObject MyObject;

    // Update is called once per frame
    void Update()
    {
        DebugBreak();
        DestroyScriptInstance();
        DestroyObject();
        DestroyObjectPlane();
        DestroyShapeShiftScript();
    }

    void DebugBreak()
    {
        if (debugBreak == true)
        {
            Debug.Break(); // Pause the game 
        }
    }

    void DestroyScriptInstance()
    {
        if (destroyScriptInstance == true)
        {
            Destroy(this); // Removes this script instance from the gameObject
        }
    }

    void DestroyObject()
    {
        if (destroyObject == true)
        {
            Destroy(gameObject); // Kills the gameObject
        }
    }

    void DestroyObjectPlane()
    {
        if (destroyObjectPlane == true)
        {
            Destroy(MyObject, 3.0f); // Kills the game object in 3 seconds after loading the object
        }

    }

    void DestroyShapeShiftScript()
    {
        if (destroyShapeShiftScript == true)
        {
            Destroy(MyObject.GetComponent<ShapeShift>()); // Kills the gameObject "ShapeShift" script component in 3 seconds after loading the object
        }
    }
}