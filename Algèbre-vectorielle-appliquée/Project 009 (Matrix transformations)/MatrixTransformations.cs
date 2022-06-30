using System.Collections.Generic;
using UnityEngine;

public class MatrixTransformations : MonoBehaviour
{
    [SerializeField] private Transform centerSquare = default;
    [SerializeField] private Transform centerRotation = default;
    [SerializeField] private List<Transform> circle_TransformList = new List<Transform>();
    [SerializeField] private List<Transform> square_TransformList = new List<Transform>();

    private List<Vector3> vertices = new List<Vector3>();
    private Vector3 square_CenterPosition = default;
    private Vector3 circle_CenterPosition = default;
    Vector3 rotate = default;

    #region UNITY_LIFETIME
    private void Awake()
    {
        // We get the position of the center of the square and circle
        square_CenterPosition = centerSquare.position;
        circle_CenterPosition = centerRotation.position;

        // Initialize the rotation angle value
        rotate = new Vector3(0, 0f, 45f);

        // Initialize the vertex position
        foreach (var vertex in square_TransformList)
        {
            vertices.Add(vertex.position);
        }
    }

    void Start()
    {
        Vector3 scale = new Vector3(1.5f, 2f, 1f);

        // Do the scaling for the green square to fit the blue square
        DoScale(scale);

        for (int i = 0; i < square_TransformList.Count; i++)
        {
            square_TransformList[i].position = vertices[i];
        }
    }

    private void Update()
    {
        // Do the rotation of the red circles around the purple circle
        DoRotate(rotate * Time.deltaTime);
    }
    #endregion

    #region TRANSFORMATIONS
    // Get the transformation matrix and apply it the vertex in order to find the new position
    private void DoScale(Vector3 deltaScale)
    {
        Matrix4x4 matT1 = GetTranslationMatrix(-square_CenterPosition);
        Matrix4x4 matT = GetScalingMatrix(deltaScale);
        Matrix4x4 matT2 = GetTranslationMatrix(square_CenterPosition);

        Matrix4x4 combo = matT2 * matT * matT1;

        // Apply the transformation matrix to the vertices
        for (int i = 0; i < square_TransformList.Count; i++) 
        {
            Vector4 currPos = new Vector4(square_TransformList[i].position.x, square_TransformList[i].position.y, square_TransformList[i].position.z, 1f);
            Vector4 newPos  = combo * currPos;
            vertices[i] = (Vector3)newPos;
        }
    }

    // Modify the position of the red circles
    private void DoRotate(Vector3 angles)
    {
        Matrix4x4 matT1 = GetTranslationMatrix(-circle_CenterPosition);
        
        Matrix4x4 matR = default;
        matR = GetRotationMatrix(angles);

        Matrix4x4 matT2 = GetTranslationMatrix(circle_CenterPosition);

        Matrix4x4 combo = matT2 * matR * matT1;

        // Apply the transformation matrix to the red circles
        for (int i = 0; i < circle_TransformList.Count; i++) 
        {
            Vector4 currPos = new Vector4(circle_TransformList[i].position.x, circle_TransformList[i].position.y, circle_TransformList[i].position.z, 1f);
            Vector4 newPos  = combo * currPos;
            circle_TransformList[i].position = (Vector3)newPos;
        }
    }
    #endregion

    #region MATRICES
    private Matrix4x4 GetTranslationMatrix(Vector3 t)
    {
        Matrix4x4 mat = Matrix4x4.identity;

        // Translation matrix 
        mat.m03 = t.x;
        mat.m13 = t.y;
        mat.m23 = t.z;

        return mat;
    }

    private Matrix4x4 GetScalingMatrix(Vector3 s)
    {
        Matrix4x4 mat = Matrix4x4.identity;

        // Scaling matrix
        mat.SetRow(0, new Vector4(s.x, 0,   0,   0));
        mat.SetRow(1, new Vector4(0,   s.y, 0,   0));
        mat.SetRow(2, new Vector4(0,   0,   s.z, 0));
        mat.SetRow(3, new Vector4(0,   0,   0,   1));

        return mat;
    }

    private Matrix4x4 GetRotationMatrix(Vector3 r)
    {
        // Convert angles from degres to radians
        Vector3 radTheta = Mathf.Deg2Rad * r;

        Matrix4x4 matR = Matrix4x4.identity;

        // Rotation matrix
        matR.m00 = Mathf.Cos(r.z);
        matR.m01 = Mathf.Sin(r.z);
        matR.m10 = -Mathf.Sin(r.z);
        matR.m11 = Mathf.Cos(r.z);

        return matR;
    }
    #endregion
}