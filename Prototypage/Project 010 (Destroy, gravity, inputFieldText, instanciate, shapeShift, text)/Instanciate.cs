using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Instanciate : MonoBehaviour
{
    [SerializeField] private GameObject CylinderPrefab;
    [SerializeField] private Vector3 Position = new Vector3(0, 15, 0);

    void OnDisable()
    {
        instanciatePrefab();
    }

    void instanciatePrefab()
    {
        CylinderPrefab = Instantiate(CylinderPrefab);
        CylinderPrefab.transform.position = Position; // define summon position for gameObject instanciation
    }
}