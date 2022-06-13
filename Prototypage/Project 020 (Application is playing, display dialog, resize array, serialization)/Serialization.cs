using System.Collections; 
using System.Collections.Generic;
using UnityEngine;

public class Serialization : MonoBehaviour
{
    [Header("SERIALIZATION")]

    // Visible
    public float var1 = 1; // visible public variable
    [SerializeField] private float var2 = 2; // serialized private variable and thus visiblee

    // Hidden
    private float var3 = 3; // hidden private variable
    [HideInInspector] public float var4 = 4; // hidden public variable
    [System.NonSerialized] public float var5 = 5; // non-serialized and thus hidden public variable
}
