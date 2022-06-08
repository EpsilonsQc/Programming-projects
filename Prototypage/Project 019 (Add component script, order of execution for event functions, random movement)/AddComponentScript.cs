using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddComponentScript : MonoBehaviour
{
    [Header("GAME OBJECT")]
    [SerializeField] GameObject myGameObject;
    [Space(10)]

    [Header("VARIABLE")]
    private bool scriptAdded;

    void Awake()
    {
        myGameObject = GameObject.Find("Add Component");
        scriptAdded = false;
    }

    public void AddNewScript()
    {
        if (scriptAdded == false)
        {
            myGameObject.AddComponent<OrderOfExecutionForEventFunctions>();
            scriptAdded = true;
        }
    }
}