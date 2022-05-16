using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class displacement : MonoBehaviour
{
    [SerializeField] private bool positionDisplacementV3Forward;
    [SerializeField] private bool positionDisplacementForward;
    [SerializeField] private bool positionDisplacementUp;
    [SerializeField] private bool positionDisplacementRight;
    [SerializeField] private int moveSpeed;

    // Update is called once per frame
    void Update()
    {
        // Move forward using Vector3 (doesn't take rotation into consideration) | Equivalent to Vector3(0, 0, 1)
        if (positionDisplacementV3Forward)transform.position += Vector3.forward * moveSpeed * Time.deltaTime;

        // Move forward using transform (take rotation into consideration)
        if (positionDisplacementForward)transform.position += transform.forward * moveSpeed * Time.deltaTime;

        // Move up using transform (take rotation into consideration)
        if (positionDisplacementUp)transform.position += transform.up * moveSpeed * Time.deltaTime;

        // Move right using transform (take rotation into consideration)
        if (positionDisplacementRight)transform.position += transform.right * moveSpeed * Time.deltaTime;
    }
}
