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

    // Produit vectoriel (2D : retourne une valeur scalaire représentant l'ampleur du résultat)
    private float CrossProduct(Vector2 vec1, Vector2 vec2)
    {
        float result = (vec1.x * vec2.y) - (vec1.y * vec2.x); // Équivalent de Vector2.Cross(vec1, vec2) [mais n'existe pas pour 2D dans Unity]

        return result;
    }

    // Produit scalaire (retourne une valeur scalaire)
    private float DotProduct(Vector2 vec1, Vector2 vec2)
    {
        float result = (vec1.x * vec2.x) + (vec1.y * vec2.y); // Équivalent de Vector2.Dot(vec1, vec2);

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

    // Changer la couleur des cibles en fonction de la position relative du radar
    private void ScanTargets()
    {
        for (int i = 0; i < targets.Length; i++)
        {
            // Dot Product: En utilisant le résultat, nous pouvons dire si l'objet est devant (> 0) ou derrière (< 0) nous.
            float dotProductResult = DotProduct(targets[i].getPosition(), radarForward);

            // Cross Product : En utilisant le résultat, nous pouvons dire si l'objet est à gauche (> 0) ou à droite (< 0).
            float crossProductResult = CrossProduct(targets[i].getPosition(), radarForward);

            if(dotProductResult > 0 && crossProductResult > 0) // Front left
            {
                targets[i].SetMyRelativeDirection(RelativeDirection.FrontLeft);
            }
            else if(dotProductResult > 0 && crossProductResult < 0) // Front right
            {
                targets[i].SetMyRelativeDirection(RelativeDirection.FrontRight);
            }
            else if(dotProductResult < 0 && crossProductResult > 0) // Rear left
            {
                targets[i].SetMyRelativeDirection(RelativeDirection.RearLeft);
            }
            else if(dotProductResult < 0 && crossProductResult < 0) // Rear right
            {
                targets[i].SetMyRelativeDirection(RelativeDirection.RearRight);
            }
        }
    }
}