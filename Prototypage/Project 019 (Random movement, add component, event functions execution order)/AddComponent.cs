using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddComponent : MonoBehaviour
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

    public void AddNewScript() // method used on a canvas button
    {
        if (scriptAdded == false)
        {
            myGameObject.AddComponent<EventFunctionsExecutionOrder>(); // add a script as component
            scriptAdded = true;
        }
    }
}