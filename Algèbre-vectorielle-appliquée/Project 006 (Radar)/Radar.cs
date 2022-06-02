using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Radar : MonoBehaviour
{
    public int nbTargets;
    public float radarSpeed = 45f;
    public float guideNorme = 50f;

    [SerializeField] GameObject radarAxes;
    [SerializeField] GameObject radarGuide;

    private Target[] targets;
    private Vector2 radarCenter = Vector2.zero;
    private Vector2 radarForward = Vector2.up;
    private float angle = 0f;

    void Start()
    {
        targets = new Target[nbTargets];
        InitTargets();
    }

    void Update()
    {
        MoveRadar();
        ScanTargets();
    }

    private float CrossProduct(Vector2 vec1, Vector2 vec2)
    {
        //TODO -> cross product for 2D vector : return a scalar
        float result = 0f;
        return result;
    }

    private float DotProduct(Vector2 vec1, Vector2 vec2)
    {
        //TODO -> dot product (also called scalar product) for 2D vector : return a scalar
        float result = 0f;
        return result;
    }

    private void InitTargets()
    {
        float range = guideNorme - 10f;
        for (int i = 0; i < targets.Length; i++)
        {
            Vector2 randPos = new Vector2(Random.Range(-range, range), Random.Range(-range, range));
            targets[i] = new Target();
            targets[i].Draw(randPos);
        }
    }

    private void MoveRadar()
    {
        angle = (angle + (radarSpeed * Mathf.Deg2Rad * Time.deltaTime)) % (2f*Mathf.PI);
        Vector2 newDir = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
        radarForward = (newDir - radarCenter).normalized;

        radarAxes.transform.Rotate(Vector3.forward, radarSpeed * Time.deltaTime);
        radarGuide.transform.position = radarForward * guideNorme;
    }

    private void ScanTargets()
    {
        // TODO : Change the color of targets depending on relative position of the radar forward

    }
}
