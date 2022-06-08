using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OrderOfExecutionForEventFunctions : MonoBehaviour
{
    [Header("VARIABLES")]
    private bool eventFixedUpdate;
    private bool eventUpdate;
    private bool eventLateUpdate;

    void Awake()
    {
        Debug.Log("Event function: Awake");

        eventFixedUpdate = false;
        eventUpdate = false;
        eventLateUpdate = false;
    }

    void Start()
    {
        Debug.Log("Event function: Start");
    }

    void OnEnable()
    {
        Debug.Log("Event function: OnEnable");
    }

    void FixedUpdate()
    {
        if(eventFixedUpdate == false)
        {
            Debug.Log("Event function: FixedUpdate");
            eventFixedUpdate = true;
        }
    }

    void Update()
    {
        if(eventUpdate == false)
        {
            Debug.Log("Event function: Update");
            eventUpdate = true;
        }
    }

    void LateUpdate()
    {
        if(eventLateUpdate == false)
        {
            Debug.Log("Event function: LateUpdate");
            eventLateUpdate = true;
        }
    }
}