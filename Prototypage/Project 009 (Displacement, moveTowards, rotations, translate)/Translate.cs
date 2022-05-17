using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class Translate : MonoBehaviour
{
    [SerializeField] private bool translateDisplacementV3World;
    [SerializeField] private bool translateDisplacementV3Self;
    [SerializeField] private bool translateDisplacementTransform;
    [SerializeField] private int moveSpeed;

    // Update is called once per frame
    void Update()
    {
        // Vector3 - Move right using space world
        if (translateDisplacementV3World)transform.Translate(Vector3.right * Time.deltaTime * moveSpeed, Space.World);

        // Vector3 - Move right using space self (locale)
        if (translateDisplacementV3Self)transform.Translate(Vector3.right * Time.deltaTime * moveSpeed, Space.Self);

        // Transform - Move right using space world
        if (translateDisplacementTransform)transform.Translate(transform.right * Time.deltaTime * moveSpeed, Space.World);
    }
}
