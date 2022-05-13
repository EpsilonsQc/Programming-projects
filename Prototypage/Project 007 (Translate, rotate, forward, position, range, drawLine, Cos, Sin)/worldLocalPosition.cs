using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class worldLocalPosition : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // Define localPosition (relative to parent)
        // gameObject.transform.localPosition = new Vector3(0,0,0);

        // Define world position (relative to scene)
        // gameObject.transform.position = new Vector3(0,0,0);
    }

    // Update is called once per frame
    void Update()
    {
        // Return cube (attached to script) local position (relative to parent)
        Debug.Log("Local Position: " + gameObject.transform.localPosition);

        // Return cube (attached to script) world position (relative to scene)
        Debug.Log("World Position: " + gameObject.transform.position);
    }
}