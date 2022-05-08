using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class MyFirstScript : MonoBehaviour
{
    public GameObject FirstScriptObject;
    public GameObject ParentSphere;
    public GameObject ChildrenSphere;

    private int quantity;
    private float half;

    // Start is called before the first frame update
    void Start()
    {
        // TEST ACTIVE SELF
        Debug.Log("gameObject is active: " + gameObject.activeSelf);
        Debug.Log("FirstScriptObject is active: " + FirstScriptObject.activeSelf);
        Debug.Log("ParentSphere is active: " + ParentSphere.activeSelf);
        Debug.Log("ChildrenSphere is active: " + ChildrenSphere.activeSelf);

        Debug.Log(gameObject.name + " is active: " + gameObject.activeSelf);
        Debug.Log(FirstScriptObject.name + " is active: " + FirstScriptObject.activeSelf);
        Debug.Log(ParentSphere.name + " is active: " + ParentSphere.activeSelf);
        Debug.Log(ChildrenSphere.name + " is active: " + ChildrenSphere.activeSelf);

        // TEST ACTIVE IN HIERARCHY
        Debug.Log(gameObject.name + " is active in hierarchy: " + gameObject.activeInHierarchy);
        Debug.Log(FirstScriptObject.name + " is active in hierarchy: " + FirstScriptObject.activeInHierarchy);
        Debug.Log(ParentSphere.name + " is active in hierarchy: " + ParentSphere.activeInHierarchy);
        Debug.Log(ChildrenSphere.name + " is active in hierarchy: " + ChildrenSphere.activeInHierarchy);

        // TEST SET ACTIVE
        gameObject.SetActive(false);
        FirstScriptObject.SetActive(false);
        ParentSphere.SetActive(false);
        ChildrenSphere.SetActive(false);
        
        // TEST ACTIVE SELF AND ACTIVE IN HIERARCHY
        Debug.Log(ChildrenSphere.name + " is active: " + ChildrenSphere.activeSelf);
        Debug.Log(ChildrenSphere.name + " is active in hierarchy: " + ChildrenSphere.activeInHierarchy);

        // TEST VARIABLE AND DEBUG.LOG
        quantity = 1;
        half = 0.5f;
        Debug.Log("Hello world!");
        Debug.Log("Answer: " + 100*5);
        Debug.Log("Quantity var equal: " + quantity);
        Debug.LogFormat("Quantity var equals: {0}. Thanks", quantity);
        Debug.LogFormat("My half var is {1} and my quantity var is {0}. Thanks", quantity, half);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
