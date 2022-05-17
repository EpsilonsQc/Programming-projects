using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class DebugLogTestComponents : MonoBehaviour
{
    void Awake()
    {
        Debug.Log(this.enabled);
        Debug.Log("PrintOnAwake: i am the Awake() method");
    }

    // Start is called before the first frame update
    void Start()
    {
        this.enabled = false;
        Debug.Log(this.isActiveAndEnabled);
        Debug.Log(isActiveAndEnabled);
        MyMethod();
    }

    void OnEnable()
    {
        Debug.Log("PrintOnEnable: script was enabled");
    }

    void OnDisable()
    {
        Debug.Log("PrintOnDisable: script was disabled");
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("PrintOnUpdate: i am the Update() method");
    }

    // MyMethod Function
    void MyMethod()
    {
        Debug.Log("PrintMyMethod: i am MyMethod()");
    }
}
