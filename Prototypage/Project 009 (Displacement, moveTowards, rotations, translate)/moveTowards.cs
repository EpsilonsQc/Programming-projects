using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveTowards : MonoBehaviour
{
    [SerializeField] private bool moveTowardsDisplacement;
    [SerializeField] private bool moveTowardsDisplacementAlt;
    [SerializeField] private int moveSpeed;

    public GameObject targetObject;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float speed = moveSpeed * Time.deltaTime;

        // Move an object until it reach it's target gameObject
        if (moveTowardsDisplacement == true)
        {
            transform.position = Vector3.MoveTowards(transform.position, targetObject.transform.position + new Vector3(0, targetObject.transform.localScale.y, 0), speed);
        }
   
        // Move an object until it reach it's target gameObject (alt method)
        if (moveTowardsDisplacementAlt == true)
        {
            Vector3 target = targetObject.transform.position + new Vector3(0, targetObject.transform.localScale.y, 0);
            transform.position = Vector3.MoveTowards(transform.position, target, speed);
        }
    }
}