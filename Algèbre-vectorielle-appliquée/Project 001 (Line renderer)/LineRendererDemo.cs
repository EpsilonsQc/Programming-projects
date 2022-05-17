using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LineRendererDemo : MonoBehaviour
{
    [SerializeField] private Vector2 point1 = new Vector2(-20, -16); // (coordonée x, y)
    [SerializeField] private Vector2 point2 = new Vector2(20, 16); // (coordonée x, y)
    [SerializeField] private LineRenderer myLineRenderer;

    void Awake()
    {
        myLineRenderer = gameObject.GetComponent<LineRenderer>();
        Debug.Assert(myLineRenderer != null, "<WARNING: Pas de lineR");
    }

    // Start is called before the first frame update
    void Start()
    {
        myLineRenderer.positionCount = 2;
        myLineRenderer.widthMultiplier = 0.25f;
    }

    // Update is called once per frame
    void Update()
    {
        SetPositions();
    }

    // SetPositions function
        private void SetPositions()
    {
        myLineRenderer.SetPosition(0, point1);
        myLineRenderer.SetPosition(1, point2);
    }
} 